def maxscore(score):
    """Takes a score, returns a tuple pair: first no is maxscore if there was
    no suprise, second no is maxscore if there was a surprise."""
    if score == 0:
        return (0, 0)
    if score % 3 == 0:
        return (score / 3, score / 3 + 1)
    if score % 3 == 1:
        return (score / 3 + 1, score / 3 + 1)
    if score % 3 == 2:
        return (score / 3 + 1, score / 3 + 2)

def qual(lst_maxscores, p):
    """Takes a list of maxscores and param p. Returns tuple (a,b,c):
    a = no. of maxscores with both entries >= p
    b = no. of maxscores with surprise score == p
    c = no. of maxscores with both entries < p."""
    a,b,c = 0,0,0
    for maxscore in lst_maxscores:
        if maxscore[1] < p:
            c += 1
        elif maxscore[0] < p:
            b += 1
        else:
            a += 1
    return (a,b,c)

# read file
f = open("B-small-attempt0.in", "r")

N = int(f.readline())  # number of cases
k = 0
while k < N:
    temp = f.readline()
    templst = temp.split()
    templst = [int(e) for e in templst]
    M = templst[0]  # number of competitors
    S = templst[1]  # number of surprises
    p = templst[2]  # threshhold
    lst_maxscores = []
    for c in templst[3:]:
        lst_maxscores.append(maxscore(c))
    (a,b,c) = qual(lst_maxscores, p)
    ans = a + min(S, b)
    print "Case #" + str(k+1) + ": " + str(ans)
    k += 1
