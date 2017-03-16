def go(s):
    s=s.rstrip()+'+'
    return sum(s[i+1]!=s[i] for i in range(len(s)-1))
        
T=input()
for t in range(1,T+1):
    print "Case #{}: {}".format(t,go(raw_input()))
