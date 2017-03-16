f=open("Brattleship", "w")
T=input()
for i in range(T):
    R,C,W=[int(x) for x in raw_input().split()]
    guess=(C/W)*R
    if C%W>0:
        guess+=W
    else:
        guess+=W-1
    print guess
    f.write("Case #%d: %d\n"%(i+1,guess))
