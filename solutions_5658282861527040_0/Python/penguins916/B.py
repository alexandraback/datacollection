import copy

f = open("B.in")
num = int(f.readline())
output = ""
for n in range(num):
    A,B,K = [int(x) for x in f.readline().strip().split(' ')]
    ss = 0
    for a in range(0,A):
        for b in range(0, B):
            ss += (a&b < K)
    output_val = str(ss)
    print output_val
    output += "Case #"+str(n+1) + ": " + output_val +"\n"

f = open ("B.out", "w+")
f.write(output)
f.close()



