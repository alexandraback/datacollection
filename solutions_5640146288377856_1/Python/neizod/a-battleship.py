print('\n'.join('Case #{}: {}'.format(case+1, (lambda col, row, width: col * (row // width) - (row % width == 0) + width)(*[int(n) for n in input().split()])) for case in range(int(input()))))
