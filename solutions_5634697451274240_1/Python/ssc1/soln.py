for c in range(int(raw_input())):
    s=raw_input()
    pre=s[0];ans=0
    for i in s[1:]+"+":
        if i!=pre:
            ans+=1
            pre=i
    print "Case #{}: {}".format(str(c+1),str(ans))