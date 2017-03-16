import sys
inp = open("B-small-attempt0.in", "r")
sys.stdout = open("B-small-out.txt", "w")
def f():
    s = inp.readline()
    if s[-1] == '\n':
        s = s[:-1]
    ans = 0
    for i in range(len(s)-1):
        if (s[i]!=s[i+1]):
            ans += 1
    if (s[-1]=='-'):
        ans += 1
    return ans 
T = int(inp.readline())
for i in range(T):
    print("Case #" + str(i+1) + ": "+str(f()))