from codejam import readfile, takeby
import math

def consume(cur_size, index, sizes):
    while index < len(sizes) and cur_size > sizes[index]:
        cur_size += sizes[index]
        index += 1
    return cur_size, index

def num_increases(n, k):    
    count = 0
    if n  == 1:
        return 1000*1000*1000*1000
    while n <= k:
        n += n - 1
        count +=1
    return count

def min_to_win(start, index, sizes):
    cur_size = start
    length = len(sizes)
    moves = 0
    if start == 1:
        return length
    while index < length:
        cur_size, index = consume(cur_size, index, sizes)
        if index >= length:
            return moves
        next_size = sizes[index]
        if min_to_win(cur_size + cur_size - 1, index, sizes) + 1 > (length-index):
            return moves + (length-index)
        moves += 1
        cur_size += cur_size -1
    return moves

def handle_case(line):
    size, count = line[0].split()
    sizes = map(int, line[1].split())
    size = int(size)
    sizes.sort()
    return min_to_win(size, 0, sizes)

lines = takeby(2,readfile()[1:])
for i, line in enumerate(lines):
    answer = handle_case(line)
    print "Case #%d: %d" % (i+1, answer)
