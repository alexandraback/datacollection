import sys
inp = open("p1.txt", "r")
sys.stdout = open("D-large-out.txt", "w")
def f():
    [N, J] = [int(c) for c in inp.readline().split()]
    ans = []
    for i in range(1<<14):
        a = (1 << 15) | (i << 1) | 1
        tmp = []
        for base in range(2, 11):
            b = 0
            for bit in range(15, -1 ,-1):
                b *= base
                b += ((a>>bit)&1)
            for div in range(2, 100):
                if b % div == 0:
                    tmp.append(div)
                    break
        if len(tmp) == 9:
            ans.append(bin(a)[2:] + " " + " ".join([str(c) for c in tmp]))
            if len(ans) == J:
                return "\n".join(ans)
T = int(inp.readline())
for i in range(T):
    print("Case #" + str(i+1) + ":")
    print(f())