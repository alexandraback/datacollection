__author__ = 'horban'
import unittest


def genb_cases(inp):
    els = inp.split()
    tnum = int(els.pop(0))
    for t in range(1, tnum+1):
        yield t, float(els.pop(0)), float(els.pop(0)), float(els.pop(0)),


def make_fact(time, income, fact_cost, fact_prod):
    return time + (float(fact_cost )/ income), income + fact_prod


def wait_victory(time, income, vicotory_money):
    return time + (float(vicotory_money) / income), income


def solve_opt(fact_cost, fact_prod, target):
    time, income = 0, 2.0
    min_vic_time, _ = wait_victory(time, income, target)
    while True:
        t1, i1 = make_fact(time, income, fact_cost, fact_prod)
        t2, i2 = wait_victory(time, income, target)
        min_vic_time = min(min_vic_time, t2)
        if min_vic_time < t1:
            return min_vic_time
        else:
            time, income = t1, i1


def test_solve(inp):
    ans = ''
    for t, fact_cost, fact_prod, target in genb_cases(inp):
        ans += 'Case #{}: {:.7f}\n'.format(t, solve_opt(fact_cost, fact_prod, target))
    return ans

def solve_file(name):
    with open(name) as fin:
        with open(name.replace('in', 'out'), 'w') as fout:
            fout.write(test_solve(fin.read()))

class TestB(unittest.TestCase):
    def setUp(self):
        self.inp = '''4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0'''

        self.out = '''Case #1: 1.0000000
Case #2: 39.1666667
Case #3: 63.9680013
Case #4: 526.1904762
'''

    def test_gen_case(self):
        self.assertEqual((1, 30.0, 1.0, 2.0), next(genb_cases(self.inp)))

    def test_gamest(self):
        self.assertEqual((25.5, 4.1), make_fact(0, 2, 51, 2.1))
        self.assertEqual((50.5, 2), wait_victory(0, 2, 101))

    def test_optim(self):
        self.assertAlmostEqual(39.1666666667, solve_opt(30, 2, 100))

    def test_case_solv(self):
        self.assertEqual(self.out, test_solve(self.inp))
