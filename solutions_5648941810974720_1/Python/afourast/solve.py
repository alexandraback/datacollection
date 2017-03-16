from collections import defaultdict

def solve():
    tri = defaultdict(int)
    for c in s:
        tri[c] +=1

    # print tri

    st = []

    if tri['Z'] > 0:
        n = tri['Z']
        st.extend([0]*n)
        for c in 'ZERO':
            tri[c]-=n

    if tri['W'] > 0:
        n = tri['W']
        st.extend([2]*n)
        for c in 'TWO':
            tri[c]-=n

    if tri['G'] > 0:
        n = tri['G']
        st.extend([8]*n)
        for c in 'EIGHT':
            tri[c]-=n

    if tri['H'] > 0:
        n = tri['H']
        st.extend([3]*n)
        for c in 'THREE':
            tri[c]-=n

    if tri['X'] > 0:
        n = tri['X']
        st.extend([6]*n)
        for c in 'SIX':
            tri[c]-=n

    if tri['R'] > 0:
        n = tri['R']
        st.extend([4]*n)
        for c in 'FOUR':
            tri[c]-=n

    if tri['S'] > 0  :
        n = tri['S']
        st.extend([7]*n)
        for c in 'SEVEN':
            tri[c]-=n

    if tri['V'] > 0 :
        n = tri['V']
        st.extend([5]*n)
        for c in 'FIVE':
            tri[c]-=n

    if tri['I'] > 0 :
        n = tri['I']
        st.extend([9]*n)
        for c in 'NINE':
            tri[c]-=n

    if tri['O'] > 0 :
        n = tri['O']
        st.extend([1]*n)
        for c in 'ONE':
            tri[c]-=n

    for c in tri:
        assert tri[c] == 0

    return sorted(st)

T = int(raw_input())

for i in range(T):
  # N = int(raw_input())
  s = raw_input()
  # s = map(int,raw_input().split())
  sol = solve()
  sol = ''.join(map(str,sol))
  print "Case #%d: %s"%(i+1,sol)
