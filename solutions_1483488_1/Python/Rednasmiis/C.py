f = open("C-large.in")
o = open("output-large.txt",'w')
t = int(f.readline())

def rec_pairs(n, B):
    pairs = 0
    n = str(n)
    length = len(n)
    these_pairs = []
    for i in range(length-1, 0, -1):
        if n[i] != '0':
            m = int(n[i:]+n[:i])
            if m > int(n) and m<=B:
                pair = [int(n),m]
                if pair not in these_pairs:
                    pairs += 1
                    these_pairs.append(pair)
                
    return pairs

for i in range(1, t+1):
    params = f.readline().split(' ')
    A = int(params[0])
    B = int(params[1])
    x = 0
    for n in range(A,B):
        x += rec_pairs(n, B)

    o.write("Case #"+str(i)+": "+str(x)+"\n")

f.close()
o.close()
