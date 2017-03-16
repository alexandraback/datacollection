__author__ = 'horban'

import unittest


def gend(inp):
    els = inp.split()
    for t in range(1, int(els.pop(0)) + 1):
        k = int(els.pop(0))
        a = map(float, els[:k])
        b = map(float, els[k:k * 2])
        els = els[k * 2:]
        yield t, a, b


def nao_fair(nao, ken):
    els = sorted([(x, 'n') for x in nao] + [(x, 'k') for x in ken])
    slate = []
    for _, who in els:
        if slate and slate[-1] == 'n' and who == 'k':
            slate.pop()
        else:
            slate += who
    return len(slate) / 2


def nao_cheat(nao, ken):
    nao, ken = map(list, (nao, ken))
    nao.sort()
    ken.sort()
    if nao[0] > ken[-1]:
        return len(nao)
    if nao[-1] < ken[0]:
        return 0
    score = 0
    while nao:
        if nao[0] < ken[0]:
            nao.pop(0)
            ken.pop()
        else:
            score += 1
            nao.pop(0)
            ken.pop(0)
    return score



def solvec_file(name):
    with open(name) as fin:
        with open(name.replace('in', 'out'), 'w') as fout:
            fout.write(solvec(fin.read()))


def solved(inp):
    res = ''
    for t, a, b in gend(inp):
        res += 'Case #{}: {} {}\n'.format(t, nao_cheat(a, b), nao_fair(a, b))
    return res

def solved_file(name):
    with open(name) as fin:
        with open(name.replace('in', 'out'), 'w') as fout:
            fout.write(solved(fin.read()))

class TestD(unittest.TestCase):
    def setUp(self):
        self.inp = '''4
1
0.5
0.6
2
0.7 0.2
0.8 0.3
3
0.5 0.1 0.9
0.6 0.4 0.3
9
0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458'''

        self.exp = '''Case #1: 0 0
Case #2: 1 0
Case #3: 2 1
Case #4: 8 4
'''

    def test_read(self):
        self.assertEqual((1, [0.5], [0.6]), next(gend(self.inp)))

    def test_nao_fair(self):
        g = gend(self.inp)
        _, nao, ken = next(g)
        self.assertEqual(0, nao_fair(nao, ken))
        _, nao, ken = next(g)
        self.assertEqual(0, nao_fair(nao, ken))
        _, nao, ken = next(g)
        self.assertEqual(1, nao_fair(nao, ken))
        _, nao, ken = next(g)
        self.assertEqual(4, nao_fair(nao, ken))

    def test_nao_cheat(self):
        g = gend(self.inp)
        _, nao, ken = next(g)
        self.assertEqual(0, nao_cheat(nao, ken))
        _, nao, ken = next(g)
        self.assertEqual(1, nao_cheat(nao, ken))
        _, nao, ken = next(g)
        self.assertEqual(2, nao_cheat(nao, ken))
        _, nao, ken = next(g)
        self.assertEqual(8, nao_cheat(nao, ken))
        
    def test_solved(self):
        self.assertEqual(self.exp, solved(self.inp))

