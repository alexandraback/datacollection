T = int(input())
for tn in range(1, T + 1):
    s = input()
    ans = s[-1] == '-'
    for i in range(len(s) - 1):
        ans += s[i] != s[i + 1]
    print("Case #%d: %d" % (tn, ans))  
