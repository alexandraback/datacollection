def qmultiply(a, b):
    minus = 0
    p, q = a, b
    if a[0] == '-':
        minus = 1-minus
        p = a[1:]
    if b[0] == '-':
        minus = 1-minus
        q = b[1:]
    result = "1"
    if p == "1":
        result = q
    elif q == "1":
        result = p
    elif (p == "i" and q == "i") or (p == "j" and q == "j") or (p == "k" and q == "k"):
        minus = 1-minus
        result = "1"
    elif p == "i" and q == "j":
        result = "k"
    elif p == "i" and q == "k":
        minus = 1 - minus
        result = "j"
    elif p == "j" and q == "i":
        minus = 1-minus
        result = "k"
    elif p == "j" and q == "k":
        result = "i"
    elif p == "k" and q == "i":
        result = "j"
    elif p == "k" and q == "j":
        minus = 1 - minus
        result = "i"
    if minus == 1:
        result = "-" + result
    return result

def qreduce(string):
    x = "1"
    for char in string:
        x = qmultiply(x, char)
    return x

def find(target, string):
    x = "1"
    if x == target:
        return 0
    for index in range(len(string)):
        x = qmultiply(x, string[index])
        if x == target:
            return index+1
    return -1

g = open("data1.txt", 'w')
with open("data.txt", 'r') as f:
    T = int(f.readline())
    for r in range(T):
        L, X = [int(x) for x in f.readline().split()]
        string = f.readline()
        if string[-1] == '\n':
            string = string[:-1]

        # Find the i
        num = min(4, X)
        search = num*string
        index = find("i", search)
        if index == -1:
            g.write("Case #%d: NO\n" % (r+1))
            continue
        X -= num
        seed = search[index:]

        # Find the j
        num = min(4, X)
        search = seed + num*string
        index = find("j", search)
        if index == -1:
            g.write("Case #%d: NO\n" % (r+1))
            continue
        X -= num
        seed = search[index:]

        # Verify remainder is k
        remainder = qreduce((X % 4)*string)
        remainder = qmultiply(qreduce(seed), remainder)
        if remainder == "k":
            g.write("Case #%d: YES\n" % (r+1))
        else:
            g.write("Case #%d: NO\n" % (r+1))
f.close()
g.close()