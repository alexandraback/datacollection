
for c in range(int(raw_input())):
    s=raw_input().strip();before="";after=""
    while len(s)>0:
        mx=max(s)
        i=len(s)-1
        while i>=0:
            if s[i]==mx:
                before+=s[i]
                after=s[i+1:]+after
                s=s[:i]
            i-=1
    print "Case #{}: {}".format(str(c+1),before+after)