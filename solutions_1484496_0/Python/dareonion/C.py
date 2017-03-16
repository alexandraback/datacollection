#!/usr/bin/env python
import sys
from collections import defaultdict

def subsets(iterable):
    results = [()]
    for i in iterable:
       more_results = [subset+(i,) for subset in results]
       results.extend(more_results)
    return results

def main(args):
    finname = '%s.in' % args[1]
    foutname = '%s.out' % args[1]
    with open(finname, 'r') as fin, open(foutname, 'w') as fout:
        T = int(fin.readline().strip())
        for i in xrange(1, T+1):
            nums = [int(n) for n in fin.readline().strip().split()]
            N = nums[0]
            S = sorted(nums[1:])
            d = defaultdict(list)
            for subset in subsets(S):
                d[sum(subset)].append(subset)
            equal_subsets_list = [subsets_ for sum_, subsets_ in d.iteritems() if len(subsets_) > 1]
            if equal_subsets_list:
                equal_subs = equal_subsets_list[0]
                sub1 = set(equal_subs[0])
                sub2 = set(equal_subs[1])
                fout.write('Case #%s:\n' % (i,))
                res1 = ' '.join(str(x) for x in sorted(sub1-sub2))
                res2 = ' '.join(str(x) for x in sorted(sub2-sub1))
                fout.write('%s\n' % (res1,))
                fout.write('%s\n' % (res2,))
            else:
                fout.write('Case #%s:\n' % (i,))
                fout.write('Impossible\n')
                
if __name__ == '__main__':
    status = main(sys.argv)
    sys.exit(status)
