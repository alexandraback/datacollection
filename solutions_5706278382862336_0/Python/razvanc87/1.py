#!/usr/bin/env python3
# encoding: utf-8

import math
import fractions as fr


def find_ancestor_elf(p, q, n):
    if p < q/2:
        n += 1
        return find_ancestor_elf(p, q/2, n)
    else:
        return n


cases_n = int(input())

for case in range(1, cases_n + 1):
    p, q = (int(i) for i in input().split('/'))
    gcd = fr.gcd(p, q)

    p = p/gcd
    q = q/gcd

    ancestors_n = math.log2(q)
    if int(ancestors_n) - ancestors_n != 0:
        print('Case #{}: {}'.format(case, 'impossible'))
        continue
    else:
        print('Case #{}: {:.0f}'.format(
            case,
            find_ancestor_elf(p, q, 1))
        )
