#! /usr/bin/python -tt

def load_file(chemin):
    from os.path import isfile
    if isfile(chemin):
        fichier = open(chemin, 'r')
        donnees = fichier.readlines()
        fichier.close()

        def format_line(line): # TODO
            return [eval(n) for n in line.split()]

    return [format_line(line) for line in donnees[1:]]


def solve(case): # TODO
    t = sum(case)
    sols = []
    for i in case:
        S = (2*t-len(case)*i)/(1.*len(case)*t)
        if S < 0 or S > 1:
            sols.append(min([(t+n-i)/(1.*t) for n in case]))
        else:
            sols.append(S)
    return sols


from sys import argv

i = 1
for case in load_file(argv[1]):
    print "Case #" + str(i) + ":",
    sol = solve(case[1:])
    for n in sol:
        print n,
    print ''
    i += 1

