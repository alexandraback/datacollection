import sys

infile = open(sys.argv[1],'r')

T = infile.readline()
T = T.rstrip()

for index in range(int(T)):
    Nstr = infile.readline().rstrip();
    L = len(Nstr)
    N = int(Nstr)
    
    seen = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    for digit in range(L):
        seen[int(Nstr[digit])] = 1;

    Ni = N
    if Ni == 0:
        print 'Case #' + str(index + 1) + ': INSOMNIA'
    else:
        while sum(seen) != 10 and Ni > 0:
            Ni = Ni + N

            Nistr = str(Ni)
            L     = len(Nistr)

            for digit in range(L):
                seen[int(Nistr[digit])] = 1;

        print 'Case #' + str(index + 1) + ': ' + str(Ni)
