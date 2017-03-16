from math import ceil

#Breaks a list l into chunks of size n (the last might have smaller size).
def list_chunks(l, n):
    chunks = []
    start = 0
    while start < len(l):
        chunks.append(l[start:start+n])
        start += n
    return chunks

def coordinate_to_num(coord, b):
    end_result = 0
    coord_len = len(coord)
    while coord_len > 1:
        end_result += (coord[0]-1)*b**(coord_len-1)
        coord = coord[1:]
        coord_len -= 1
    end_result += coord[0]
    return end_result

def gold_scrubs(k, c, s):
    min_grads = int(ceil(float(k)/c))
    if min_grads > s:
        return "IMPOSSIBLE"
    else:
        coordinate_nums = [i%k + 1 for i in range(min_grads*c)]
        coordinates = list_chunks(coordinate_nums, c)
        return map(lambda coord: coordinate_to_num(coord, k), coordinates)

def list_to_string(l):
    if len(l) == 1:
        return str(l[0])
    else:
        return reduce(lambda x, y: str(x) + " " + str(y), l)

f = open("input.txt", 'r')
g = open("output.txt", 'w')

num_cases = int(f.readline().strip())
for case in range(1, num_cases+1):
    kcs = map(lambda x: int(x), f.readline().strip().split())
    k, c, s = kcs[0], kcs[1], kcs[2]
    result = gold_scrubs(k,c,s)
    if result == "IMPOSSIBLE":
        g.write("Case #" + str(case) + ": IMPOSSIBLE")
    else:
        g.write("Case #" + str(case) + ": " + list_to_string(result))
    if case != num_cases:
        g.write("\n")
