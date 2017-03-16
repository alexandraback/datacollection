

t=int(raw_input())
for tc in range(t):
    s=raw_input()
    cnt={}
    for c in "QWERTYUIOPLKJHGFDSAZXCVBNM":
        cnt[c]=0
    for c in s:
        cnt[c]+=1
    x0=cnt["Z"]
    x2=cnt["W"]
    x4=cnt["U"]
    x6=cnt["X"]
    x8=cnt["G"]
    x1=cnt["O"]-x2-x4-x0
    x3=cnt["H"]-x8
    x5=cnt["F"]-x4
    x7=cnt["V"]-x5
    x9=cnt["I"]-x8-x6-x5
    s="0"*x0+"1"*x1+"2"*x2+"3"*x3+"4"*x4+"5"*x5+"6"*x6+"7"*x7+"8"*x8+"9"*x9
    print "Case #"+str(tc+1)+": "+s

