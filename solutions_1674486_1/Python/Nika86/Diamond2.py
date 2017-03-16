import sys;

sys.setrecursionlimit(10000);

f_in = open('A-large.in','r');
f_out = open('A-large.out.txt','w');

T = int(f_in.readline());
RelList = [];
InhList = [];

def updateRels(f):
    for pp in InhList[f]:
        if RelList[pp]:
            return True;
        else:
            RelList[pp] = True;
            if updateRels(pp):
                return True;
    return False;
    

for t in range(T):
    N = int(f_in.readline());
    InhList = [];
    for n in range(N):
        InhList += [[]];
    ans = False;
    for n in range(N):
        inp_str = f_in.readline();
        inp_lst = inp_str.split(' ');
        M = int(inp_lst[0]);
        for m in range(M):
            InhList[n] += [int(inp_lst[m+1])-1];
            
    for n in range(N):
        RelList = [];
        for n2 in range(N):
            RelList += [False];
        ans = ans or updateRels(n);

    f_out.write('Case #'+str(t+1)+': ');
    if (ans):
        f_out.write('Yes\n');
    else:
        f_out.write('No\n');

f_in.close();
f_out.close();
