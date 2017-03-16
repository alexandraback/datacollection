#!/usr/bin/python

import sys
import functools

with open(sys.argv[1]) as f:
    lines = f.readlines();

lines.pop(0)

n_case = 0
while lines:
    line = lines.pop(0)
    A,B = [int(c) for c in line.split(' ')]
    line = lines.pop(0)
    prob = [float(c) for c in line.split(' ')]
    neg_prob = [1 - c for c in prob]
    ret = 0

    prob_escrito_bien = functools.reduce(lambda x, y: x*y, prob)
    escribiendo = ((B-A+1) * prob_escrito_bien + ((2*B-A+2) * (1 - prob_escrito_bien)))
    empezar = B+2
    borrando = empezar
    for x in range(A-1):
        x += 1
        caso_bueno = B-A+1+x*2
        if caso_bueno > empezar:
            break;
        caso_malo = caso_bueno + B + 1
        prob_caso_bueno = functools.reduce(lambda x, y: x*y, prob[:-x])
        resultado = caso_bueno*prob_caso_bueno + caso_malo*(1 - prob_caso_bueno)
        if resultado > borrando:
            break;
        borrando = resultado

    n_case += 1
    print("Case #%d: %.6f" % (n_case, min(escribiendo,empezar,borrando)))
