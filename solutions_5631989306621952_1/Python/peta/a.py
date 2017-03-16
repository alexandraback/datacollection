import sys

t = int(sys.stdin.readline())
for i in range(t):
    s = sys.stdin.readline().strip()
    new_s = ['.']*3000
    new_s[1500] = s[0]
    b, e = 1500, 1500
    for j in range(1, len(s)):
        if new_s[b] <= s[j]:
            b -= 1
            new_s[b] = s[j]
        else:
            e += 1
            new_s[e] = s[j]
    print("Case #" + str(i+1) + ": " + "".join(new_s[b:e+1]))

