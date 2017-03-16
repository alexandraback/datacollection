from pefuncs import digits_to_number, digits, k_sublists

def pows_to_num(l):
    return sum(map(lambda x: 10**x, l))

def easy_jamcoins(n, j):
    all = []
    evens = range(2,n-1,2)
    odds = range(1,n-1,2)
    for sublistlen in range(n/2-1):
        even_sublists = k_sublists(evens, sublistlen)
        odd_sublists = k_sublists(odds, sublistlen)
        for esl in even_sublists:
            for osl in odd_sublists:
                all.append([pows_to_num(esl+osl+[0,n-1]), range(3,12)])
                if len(all) == j:
                    return all
    print "insufficient"
    return all

#Given a list of digits that are either zero or one, returns what numbers they amount to in bases 2-10.
def base_nums(digs):
    return [digits_to_number(digs,b) for b in range(2,11)]

def verify_easiness(l):
    bns = base_nums(digits(l[0]))
    for i in range(9):
        if bns[i]%l[1][i] != 0:
            return False
    return True

nvar = 32
jvar = 500

g = open("output.txt", 'w')
g.write("Case #1: \n")

for jc in easy_jamcoins(nvar, jvar):
    g.write(str(jc[0]))
    for div in jc[1]:
        g.write(" " + str(div))
    g.write('\n')
