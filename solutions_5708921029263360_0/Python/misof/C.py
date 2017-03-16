import subprocess

def var(j,p,s): return 'x_{}_{}_{}'.format(j+1,p+1,s+1)

T = int( input() )
for tc in range(T):
    J, P, S, K = [ int(x) for x in input().split() ]
    f = open('temp.lp','w')
    f.write('max: ' + ' '.join(var(j,p,s) for j in range(J) for p in range(P) for s in range(S)) + ';\n')
    for j in range(J):
        for p in range(P):
            for s in range(S):
                f.write('{} <= 1;\n'.format(var(j,p,s)))
    for j in range(J):
        for p in range(P):
            f.write(' + '.join(var(j,p,s) for s in range(S)) + ' <= {};\n'.format(K) )
    for j in range(J):
        for s in range(S):
            f.write(' + '.join(var(j,p,s) for p in range(P)) + ' <= {};\n'.format(K) )
    for p in range(P):
        for s in range(S):
            f.write(' + '.join(var(j,p,s) for j in range(J)) + ' <= {};\n'.format(K) )
    for j in range(J):
        for p in range(P):
            for s in range(S):
                f.write('int {};\n'.format(var(j,p,s)))
    f.close()

    subprocess.call('lp_solve temp.lp > temp.out', shell=True) 
    output = open('temp.out').readlines()
    for line in output:
        if 'function:' in line:
            answer = int( line.split()[-1] )
    print('Case #{}: {}'.format(tc+1,answer))
    for line in output:
        if '_' in line:
            tokens = line.strip().split()
            if tokens[-1] == '1':
                vals = tokens[0].split('_')
                print('{} {} {}'.format(*vals[1:]))

