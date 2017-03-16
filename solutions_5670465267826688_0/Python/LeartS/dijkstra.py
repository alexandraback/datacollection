import sys

multiplication_matrix = (
    ( '1',  'i',  'j',  'k'), # 1
    ( 'i', '-1',  'k', '-j'), # i
    ( 'j', '-k', '-1',  'i'), # j
    ( 'k',  'j', '-i', '-1'), # k
)

table = {'1': 0, 'i': 1, 'j': 2, 'k': 3}


def quad_multiply(a, b):
    raw_result = multiplication_matrix[table[a[-1]]][table[b[-1]]]
    
    if (a[0] == '-' and b[0] == '-') or not (a[0] == '-' or b[0] == '-'):
        return raw_result
    else:
        # invert the sign
        return raw_result[-1] if raw_result[0] == '-' else '-' + raw_result


T = int(sys.stdin.readline().strip())
for case_index in range(1, T+1):
    L, X = map(int, sys.stdin.readline().strip().split())
    mispelling_atom = sys.stdin.readline().strip()
    mispelling = mispelling_atom * X
    index = 0
    first_split_index = None
    second_split_index = None

    # Search for a 'i' from the start
    product = '1'
    for char in mispelling:
        product = quad_multiply(product, char)
        index += 1
        if product == 'i':
            first_split_index = index
            break
    else:
        print 'Case #{}: NO'.format(case_index)
        continue

    # Search for a 'j' from where we started
    product = '1'
    for char in mispelling[index:]:
        product = quad_multiply(product, char)
        index += 1
        if product == 'j':
            second_split_index = index
            break
    else:
        print 'Case #{}: NO'.format(case_index)
        continue

    # The reamining part must be a 'k'
    product = '1'
    for char in mispelling[index:]:
        product = quad_multiply(product, char)
    if product == 'k':
        # print 'Case #{}: YES [{} {} {}]'.format(
        #     case_index, mispelling[:first_split_index],
        #     mispelling[first_split_index:second_split_index], mispelling[second_split_index:])
        print 'Case #{}: YES'.format(case_index)
    else:
        print 'Case #{}: NO'.format(case_index)
