f_in = open('A-small.in.txt','r');
f_out = open('A-small.out.txt','w');

T = int(f_in.readline());

for t in range(T):
    inp_str = f_in.readline();
    inp_lst = inp_str.split(' ');
    N = int(inp_lst[0]);
    J = []; X = 0;
    for n in range(N):
        J += [int(inp_lst[n+1])];
        X += int(inp_lst[n+1]);
    JS = J[:];
    JS.sort();
    JS += [2*X];
    
    Xtemp = 0;
    L = 0.0;
    for n in range(N):
        if (Xtemp + (n+1)*(JS[n+1]-JS[n]) <= X):
            Xtemp += (n+1)*(JS[n+1]-JS[n]);
        else:
            L = JS[n] + (X + 0.0 - Xtemp)/(n+1);
            break;
    
    f_out.write('Case #'+str(t+1)+': ');
    for n in range(N):
        ans = max(0,100.0*(L - J[n])/X);
        f_out.write(str(ans));
        if (n < N-1):
            f_out.write(" ");
    f_out.write('\n');

f_in.close();
f_out.close();
