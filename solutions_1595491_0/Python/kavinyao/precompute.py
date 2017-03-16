def no_2_aprt(triplet):
    return (triplet[0] - triplet[2]) <= 2

def triplets(total):
    """
    generates triplets with following constraints:
    1. the sum is total
    2. no two scores are 2 apart
    """
    _max = (total+4)/3
    _max = 10 if _max > 10 else _max
    possible = []
    for first in (_max, _max-1):
        for second in (first, first-1, first-2):
            third = total - first - second
            if third > second or second < 0 or third < 0:
                continue
            possible.append((first, second, third))
    possible = filter(no_2_aprt, possible)
    return possible

if __name__ == '__main__':
    with open('mapping.py', 'wb') as mapping_file:
        mapping_file.write('mapping = [\n')
        for i in range(0, 31):
            mapping_file.write('    %s,\n' % triplets(i))
        mapping_file.write(']')
