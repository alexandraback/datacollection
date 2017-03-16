def intput():
    return int(input())
def insplit():
    return input().split()
def intsplit():
    a = input().split()
    for i in range(len(a)):
        a[i] = int(a[i])
    return a
def strtolist(a):
    list = []
    for c in a:
        list.append(c)
    return list
def s(a):
    return str(a)

T = intput()
for t in range(T):
    line = input()
    blank = ""
    for s in line:
        if len(blank) == 0:
            blank = s
        else:
            # if bigger
            if s >= blank[0]:
                blank = s + blank
            else:
                blank = blank + s
    print("Case #" + str(t+1) + ": " + str(blank))
