#Henry Maltby
#Code Jam 2016

def slides(B, M):
    """
    Notes upper limit of paths in B-vertex dag from source to sink is 2^(B-2).
    Gleefully murders some list comprehensions to make examples. Based on a
    simplistic "source-heavy" dag. Uses binary representation.
    """
    if M > pow(2, B - 2):
        return "IMPOSSIBLE"
    text = "POSSIBLE\n"
    if M == pow(2, B - 2):
        text += "\n".join(["".join(['0' for x in range(i + 1)] + \
         ['1' for x in range(B - i - 1)]) for i in range(B)])
        return text
    binrep = bin(M)[2:]
    depth = len(binrep)
    binrep = '0'*(B - depth - 1) + binrep + '0'
    text += "\n".join(["".join(['0' for x in range(i + 1)] + \
     ['1' for x in range(depth - i)] + \
     ['0' for x in range(B - (i + 1) - pos_part(depth - i) - 1)] + \
     [binrep[B - i - 1] if i < B-1 else '']) for i in range(B)])
    if text[-1] == ' ':
        text = text[:-1]
    return text

def pos_part(x):
    if x < 0:
        return 0
    return abs(x)

def check_slide(txt):
    if txt=="IMPOSSIBLE":
        return "ok"
    arr = [[int(x) for x in line.split()] for line in txt.split('\n')[1:]]
    n = len(arr)
    pts = [0 for i in range(n)]
    pts[0] = 1
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 1:
                pts[j] += pts[i]
    return n, pts[-1]

f = open('B-large.in')
g = open('B-large.out', 'w')

T = int(f.readline())
for i in range(T):
    B, M = [int(x) for x in f.readline().split(' ')]
    ans = slides(B, M)
    g.write("Case #" + str(i + 1) + ": " + ans + "\n")
    #if check_slide(ans)=="ok":
    #    print(str(B) + " " + str(M))
    #elif (B, M) != check_slide(ans):
    #    print("Error found with Case #" + str(i + 1))