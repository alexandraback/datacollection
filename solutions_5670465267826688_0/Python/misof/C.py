# quaternion representation: [0,1,2,3] = [1,i,j,k], [4,5,6,7] = [-1,-i,-j,-k]

quat_trans = { 'i':1, 'j':2, 'k':3 }
quat_mult_table = [ [0,1,2,3], [1,4,3,6], [2,7,4,1], [3,2,5,4] ]

def quat_multiply(a,b):
    global quat_mult_table
    sign_a, abs_a, sign_b, abs_b = a//4, a%4, b//4, b%4
    return ( quat_mult_table[abs_a][abs_b] + 4*sign_a + 4*sign_b ) % 8

def next_states(state,q):
    g, p = state
    r = quat_multiply(p,q)
    answer = [ (g,r) ]
    if (g,r) in [ (0,1), (1,2) ]: answer.append( (g+1,0) )
    return answer

T = int( input() )
for t in range(1,T+1):
    L, X = [ int(z) for z in input().split() ]
    S = input()
    S *= X
    states = set([ (0,0) ])
    for s in S:
        q = quat_trans[s]
        new_states = set([ nstate for state in states for nstate in next_states(state,q) ])
        states = new_states
    print('Case #{}: {}'.format(t,'YES' if (2,3) in states else 'NO'))
