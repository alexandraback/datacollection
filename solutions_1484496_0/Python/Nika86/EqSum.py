f_in = open('C-small.in.txt','r');
f_out = open('C-small.out.txt','w');

def eq0(N,L,S):
    ans = [];
    allzeros = True;
    sumset = 0;
    if (len(L) < N):
        ans = eq0(N,L+[0],S);
        if ( len(ans) == 0 ):
            ans = eq0(N,L+[-1],S);
        if ( len(ans) == 0 ):
            ans = eq0(N,L+[1],S);
        return ans;
    else:
        for n in range(N):
            sumset += (L[n]*S[n]);
            if (L[n] != 0):
                allzeros = False;
        if ((sumset == 0) and (allzeros == False)):
            return L;
        else:
            return [];
        

T = int(f_in.readline());

for t in range(T):
    inp_str = f_in.readline();
    inp_lst = inp_str.split(' ');
    N = int(inp_lst[0]);
    S = [];
    for n in range(N):
        S += [int(inp_lst[n+1])];

    finalSet = eq0(N,[],S);

    if (len(finalSet) == 0):
        f_out.write('Case #'+str(t+1)+': Impossible\n');
    else:
        f_out.write('Case #'+str(t+1)+':\n');
        for n in range(N):
            if (finalSet[n]==1):
                f_out.write(str(S[n])+" ");
        f_out.write('\n');
        for n in range(N):
            if (finalSet[n]==-1):
                f_out.write(str(S[n])+" ");
        f_out.write('\n');

f_in.close();
f_out.close();
