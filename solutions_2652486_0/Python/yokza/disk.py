def upd(numbers):
    if numbers[2] < 5:
        numbers[2]+=1
        return numbers

    if numbers[1] < 5:
        numbers[1] += 1
        numbers[2] = 2
        return numbers

    if numbers[0] < 5:
        numbers[0] += 1
        numbers[1] = 2
        numbers[2] = 2
        return numbers
    return []


def check(products, numbers):
    for num in filter(lambda x: x!=1, products):
        if num in numbers:
            continue
        if numbers[0]* numbers[1] == num:
            continue
        if numbers[0] * numbers[1] * numbers [2] == num:
            continue
        if numbers[1] * numbers[2] == num:
            continue
        return False
    return True



def solve(file_name, out_file_name):
    out_file = open(out_file_name, 'w')
    in_file = open(file_name, 'r')
    out_file.write('Case #1:\n')

    cases = int(in_file.readline())
    R, N, M, K = map(int, in_file.readline().split())
    for xr in xrange(R):
        products = map(int, in_file.readline().split())
        nums = [2] * N
        while nums:
            if check(products, nums):
                out_file.write('%s\n' % ''.join(map(str,nums)))
                break
            nums = upd(nums)
        if not nums:
            out_file.write('222\n')

    out_file.close()


if __name__ == '__main__':
    import sys
    file_name = sys.argv[1]
    out_file_name = sys.argv[2]
    solve(file_name, out_file_name)
