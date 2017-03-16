in_file = open('A-large.in', 'r')
out_file = open('out.txt', 'w')

total_case_count = int(in_file.readline())

for i in range(total_case_count):
    row, column, length = [int(x) for x in in_file.readline().split()]

    div = column // length
    left = column - div * length

    if div == 1:
        answer = length
    else:
        answer = div - 1 + length

    if left != 0:
        answer += 1

    out_file.write('Case #{}: {}\n'.format(i + 1, answer + (row - 1) * (column // length)))


in_file.close()
out_file.close()