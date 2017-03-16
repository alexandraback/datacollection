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


def solve(reste):
    sommes = {0:[]}
    for n in reste:
        for (s,liste) in sommes.items():
            if sommes.has_key(s+n):
                return (liste + [n],sommes[s+n])
            else:
                sommes[s+n] = liste + [n]
    return "Impossible"
    


from sys import argv

i = 1
for case in load_file(argv[1]):
    print "Case #" + str(i) + ":"
    sol = solve(case[1:])
    if sol == "Impossible":
        print sol
    else:
        for j in sol[0]:
            print j,
        print ''
        for j in sol[1]:
            print j,
        print ''
    i += 1

