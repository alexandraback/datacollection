#!/usr/bin/python
import itertools
def gen_str(l):
    for s in itertools.product(range(2), repeat=l):
        out = '1'
        for c in s:
            out += str(c)
        yield out + '1'

results = []
c = 0
for cj in gen_str(14):
    _result = []
    _good = True
    for b in range(2,11):
        n = int(cj,b)
        for d in range(2,10000):
            div_found = False
            if not n%d:
                _result.append(d)
                div_found =  True
                break
        if not div_found:
            _good = False
            break
    if _good:    
        results.append((cj,_result))
        c += 1
    if c == 50:
        break

with open('c.out', 'w') as f:
    f.write('Case #1:\n')
    for r in results:
        f.write(r[0])
        for d in r[1]:
            f.write(' {}'.format(d))
        f.write('\n')
