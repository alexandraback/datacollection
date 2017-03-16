def function(B,M):
    if 2**(B-2) < M:
        return 'IMPOSSIBLE'
    mat = init(B)
    pos = 2**(B-2)
    s = 0
    while pos != M:
        i = s+1
        p = 2**(B-i-2)
        while pos - p >= M:
            mat[s][i] = 0
            pos -= p
            i += 1
            p = 2**(B-i-2)
        s = i
    return 'POSSIBLE\n' + '\n'.join(list(map(lambda x: ''.join(list(map(str,x))), mat)))



def init(B):
    mat = []
    for i in range(B):
        mat.append(([0]*(i+1)) + [1]*(B-i-1))
    return mat



# MAIN
# input like this:
# T
# B,M  ----> Case #1: m
# B,M  ----> Case #1: m
with open('input.txt', 'r') as f:
    for i, line in enumerate(f.readlines()[1:]):
        print('Case #' + str(i+1) + ': ' + str(function(*list(map(int,line[:-1].split())))))


