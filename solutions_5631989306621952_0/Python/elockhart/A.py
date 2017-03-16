def solve(s):
    if len(s) == 0: return ""
    m = max(s)
    p = s.rfind(max(s))
    return m + solve(s[:p]) + s[1+p:]

for C in range(int(input())):
    print("Case #{}: {}".format(1+C, solve(input())))
    
