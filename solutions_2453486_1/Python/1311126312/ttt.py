def s2a(s):
    a=[]
    for i in s:
        a.append(i)
    return a

def test(t, cp):
    for i in range(0,4):
        win=True
        for j in range(0,4):
            if t[i][j]==cp or t[i][j]=="T":
                win=win and True
            else: win=False
        if win: return True
    for i in range(0,4):
        win=True
        for j in range(0,4):
            if t[j][i]==cp or t[j][i]=="T":
                win=win and True
            else: win=False
        if win: return True
    win=True
    if( (t[0][3]==cp or t[0][3]=="T") and (t[1][2]==cp or t[1][2]=="T") and  (t[2][1]==cp or t[2][1]=="T") and  (t[3][0]==cp or t[3][0]=="T")):return True
    if( (t[3][3]==cp or t[3][3]=="T") and  (t[2][2]==cp or t[2][2]=="T") and  (t[1][1]==cp or t[1][1]=="T") and  (t[0][0]==cp or t[0][0]=="T")):return True    
    return False
                
def draw(t):
    for i in t:
        for j in i:
            if j==".":
                return False
    return True
    
data=open("ttt.in").readlines()
out=open("ttt.out","w")
t=int(data[0])
cl=0
case=1
for i in xrange(t):
    cl+=1
    fbf=[]
    for j in range(cl, cl+4):
        fbf.append(s2a(data[j][:-1]))
    cl+=4
    X=test(fbf,"X")
    O=test(fbf,"O")
    D=draw(fbf)
    if D and not O and not X:
        out.write("Case #"+str(case)+": "+"Draw"+"\n")
    elif not X and O:
        out.write("Case #"+str(case)+": "+"O won"+"\n")
    elif X and not O:
        out.write("Case #"+str(case)+": "+"X won"+"\n")
    elif not X and not O:
        out.write("Case #"+str(case)+": "+"Game has not completed"+"\n")
    
    case+=1

