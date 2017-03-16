answers = map(lambda s: tuple(s.split()), open("answers.txt", "r").readlines())
answersD = {}
for i, j in answers:
    answersD[i] = j

T = int(raw_input())
for t in range(1,T+1):
    print "Case #%d: %s" % (t, answersD[raw_input()])
