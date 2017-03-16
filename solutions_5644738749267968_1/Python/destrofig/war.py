import sys
import itertools
import random
import logging
import time
#import heapq
from collections import deque

def get_war_ans(naomi_blocks, ken_blocks):
    # tests seem to show that order doesn't matter
    # can't prove it rigorously  :/
    
    #heapq.heapify(naomi_blocks)
    #heapq.heapify(ken_blocks)
    naomi_blocks.sort()
    ken_blocks.sort()
    naomi_blocks = deque(naomi_blocks)
    ken_blocks = deque(ken_blocks)
    score = 0
    while naomi_blocks:
        naomi_val = naomi_blocks.pop()
        if ken_blocks[-1] > naomi_val:
            ken_val = ken_blocks.pop()
        else:
            ken_val = ken_blocks.popleft() 
            
        
        if naomi_val > ken_val:
            score += 1
    return score
        

def get_dec_war_ans(naomi_blocks, ken_blocks):
    naomi_blocks = naomi_blocks[:]
    ken_blocks = ken_blocks[:]
    naomi_blocks.sort()
    ken_blocks.sort()
    naomi_blocks = deque(naomi_blocks)
    ken_blocks = deque(ken_blocks)
    score = 0
    while naomi_blocks:
        while naomi_blocks and naomi_blocks[-1] > ken_blocks[-1]:
            score += 1
            naomi_blocks.pop()
            ken_blocks.pop()
        if naomi_blocks:
            naomi_blocks.popleft()
            ken_blocks.pop()
    return score
        
        
    

def get_ans(naomi_blocks, ken_blocks):
    naomi_blocks.sort()
    ken_blocks.sort()
    war_ans = get_war_ans(naomi_blocks, ken_blocks)
    dec_war_ans = get_dec_war_ans(naomi_blocks, ken_blocks)
    return dec_war_ans, war_ans

def solve(fd):
    case_count = int(fd.readline())
    solution = []
    for case_no in xrange(1,case_count+1):
        block_count = int(fd.readline())
        naomi_blocks = map(float, fd.readline().split())
        ken_blocks = map(float, fd.readline().split())
        ans = get_ans(naomi_blocks, ken_blocks)
        solution.append("Case #%d: %d %d" % (case_no, ans[0], ans[1]))
    return '\n'.join(solution)
    


def main():
    logging.basicConfig(level=logging.DEBUG)
    if sys.argv[1:]:
        fn = sys.argv[1]
        with open(fn, 'r') as fd:
            res = solve(fd)
        print res
    else:
        test()
        test2()
        test_big()

def test_one_ex(naomi_blocks, ken_blocks):
    scores = []
    assert len(naomi_blocks) == len(ken_blocks)
    for order in itertools.permutations(range(len(naomi_blocks))):
        score = 0
        ken_workset = ken_blocks[:]
        for block_no in order:
            naomi_val = naomi_blocks[block_no]
            ken_answer = 0
            for alt_no, alt in enumerate(ken_workset):
                if alt > naomi_val:
                    ken_answer = alt_no
                    break
            #print ken_answer, ken_workset
            ken_val = ken_workset[ken_answer]
            if naomi_val > ken_val:
                score += 1
            #naomi_blocks.pop(block_no) # not deleting anything of naomi
            ken_workset.pop(ken_answer)
        scores.append(score)
    if len(set(scores)) != 1:
        raise Exception("Possible scores: %s" % scores)
    return scores

def test2():
    for ex_count in xrange(10):
        logging.info("Ex no %s", ex_count)
        for block_count in xrange(5):
            #block_count = 5
            values = range(block_count * 2)
            random.shuffle(values)
            naomi_blocks = values[:block_count]
            ken_blocks = values[block_count:]
            naomi_blocks.sort()
            ken_blocks.sort()
            scores = test_one_ex(naomi_blocks, ken_blocks)
            #print len(set(scores))
    
def test_big():
    block_count = 100000
    blocks = range(block_count * 2)
    random.shuffle(blocks)
    naomi_blocks = blocks[:block_count]
    ken_blocks = blocks[block_count:]
    tic = time.time()
    get_ans(naomi_blocks, ken_blocks)
    toc = time.time() - tic
    logging.info("Got answer for 2x%d blocks in %0.4f seconds", block_count, toc)
    

def test():
    import StringIO
    test_case = """4
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
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458
"""
    expected_out = """Case #1: 0 0
Case #2: 1 0
Case #3: 2 1
Case #4: 8 4
"""
    out = solve(StringIO.StringIO(test_case))
    #print out
    #print expected_out
    assert out.strip() == expected_out.strip()
        
    
if __name__ == '__main__':
    main()