t = int(input());
for i in range(t):
    s = raw_input();
    r = s[0];
    front = [];
    tail = "";
    l = s[0];
    for c in s[1:]:
        if c>= l:
            l=c
            front.append(c)
        else:
            tail = tail+c
    front = "".join([c for c in reversed(front)])
    print "case #%s: %s" %(i+1,front+r+tail)
