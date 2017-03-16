import sys
from itertools import product
from collections import defaultdict
from itertools import combinations

def check(result, k):
    jp_map = defaultdict(lambda: 0)
    js_map = defaultdict(lambda: 0)
    ps_map = defaultdict(lambda: 0)
    for j, p, s in result: 
        jp_k = j + p
        js_k = j + s
        ps_k = p + s
        jp_map[jp_k] += 1
        js_map[js_k] += 1
        ps_map[ps_k] += 1
        jp = jp_map[jp_k]
        js = js_map[js_k]
        ps = ps_map[ps_k]
        if jp > k or js > k or ps > k:
            return False
    return True

def run_test(case_number, generator):
    j, p, s, k = (int(x) for x in next(generator).split())
    m = j*p*s

    full = list(product((str(x + 1) for x in range(j)), (str(x + 1) for x in range(p)), (str(x + 1) for x in range(s))))
    jp_map = defaultdict(lambda: 0)
    js_map = defaultdict(lambda: 0)
    ps_map = defaultdict(lambda: 0)

    result = []
    for j, p, s in full:
        jp_k = j + p
        js_k = j + s
        ps_k = p + s
        jp = jp_map[jp_k]
        js = js_map[js_k]
        ps = ps_map[ps_k]
        if jp < k and js < k and ps < k:
            jp_map[jp_k] += 1
            js_map[js_k] += 1
            ps_map[ps_k] += 1
            result.append((j, p, s))

    found = True
    while found and len(result) < len(full):
        found = False
        for new_result in combinations(full, len(result) + 1):
            if check(new_result, k):
                found = True
                result = new_result
                break

    print('Case #%d: %d' % (case_number, len(result)))
    for res in result:
        print('%s %s %s' % res)

def main():
    generator = get_file()
    number_of_tests = int(next(generator))
    for test in range(1, number_of_tests + 1):
        run_test(test, generator)

def get_file():
    for line in sys.stdin:
        yield line
        
if __name__ == '__main__':
    main()