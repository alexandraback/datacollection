#0 mod 3
#0,0,0 (+0)
#0,1,2 (s,+1)

#1 mod 3
#0,0,1 (+1)
#0,2,2 (s,+1)

#2 mod 3
#0,0,2 (s,+2)
#0,1,1 (+1)

#Being suprising always increase the score

for case in range(input()):
    print "Case #"+str(case+1)+":",
    inp=map(int,raw_input().split())
    S=inp[1]
    p=inp[2]
    totals=inp[3:]
    passed=0
    borderline=0
    for total in totals:
        #small numbers special case
        if total<p:
            continue
        elif total==3:
            if p<=1:
                passed+=1
            elif p==2:
                borderline+=1
        elif (total/3 + (total%3>0))>=p:
            passed+=1
        elif (total/3 + 1 + (total%3==2)) >= p:
            borderline+=1
    print passed+min(borderline,S)
