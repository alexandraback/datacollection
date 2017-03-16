from itertools import product

T = int(input())
for I in range(1, T+1):
    result = ''
    a, b = input().split()

    digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    qcounta = ([digits for k in a if k == '?'])
    qcountb = ([digits for k in b if k == '?'])

    posva = list(product(*qcounta))
    posvb = list(product(*qcountb))

    posvalues = []

    for k in range(0, len(posva)):
        # fillA
        filla = [x for x in a]
        c = 0
        for i in range(0, len(a)):
            if a[i] == '?':
                filla[i] = posva[k][c]
                c += 1

        sa = ''.join(filla)

        for j in range(0, len(posvb)):
            fillb = [x for x in b]
            c = 0
            for i in range(0, len(b)):
                if b[i] == '?':
                    fillb[i] = posvb[j][c]
                    c += 1
            sb = ''.join(fillb)
            numdif = int(sb) - int(sa)
            numdif = abs(numdif)

            posvalues.append((numdif, sa, sb))

    posvalues.sort()
    result = posvalues[0][1] + " " + posvalues[0][2]

    print("Case #%d: %s" % (I, str(result)))
