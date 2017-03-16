# k*R <= Sk <= E+(k-1)R
# => R <= E-Sk+k*R <= E
# f = v1*S1+v2*(S2-S1)+...+vn*(Sn-Sn-1)
#   = (v1-v2)S1+(v2-v3)S2+...+(vn-1-vn)Sn-1+vn*Sn

def f(E, R, N, v):
    res = 0
    if R >= E:
        res = E * sum(v)
    else:
        res = 0
        v.append(0)
        for i in range(N):
            if(v[i] < v[i+1]):
                res += (v[i]-v[i+1])*(i+1)*R
            else:
                res += (v[i]-v[i+1])*(E+i*R)
    return res

nCase = int(raw_input())
for _ in range(1, nCase + 1):
    E, R, N = map(int, raw_input().split())
    v = map(int, raw_input().split())
    print 'Case #%d: %d' % (_, f(E, R, N, v))
