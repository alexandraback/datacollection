def test(boxes, toys, i, j):
    if boxes[j + 1] == toys[i + 1]:
        return max([boxes[j], toys[i]])

def choose(boxes, toys, i, j, shipped):
    if i >= n or j >= m:
        return shipped
    if toys[i + 1] == boxes[j + 1]:
        if toys[i] >= boxes[j]:
            shipped += boxes[j]
            toys[i] -= boxes[j]
            boxes[j] = 0
            j += 2
            if not toys[i]:
                i += 2
        else:
            shipped += toys[i]
            boxes[j] -= toys[i]
            toys[i] = 0
            i += 2
            if not boxes[j]:
                j += 2

        a = choose([box for box in boxes], [toy for toy in toys], i, j, shipped)
        return a
    else:
        a = choose([box for box in boxes], [toy for toy in toys], i + 2, j, shipped)
        b = choose([box for box in boxes], [toy for toy in toys], i, j + 2, shipped)
        if a > b:
            return a
        else:
            return b

inp = open("input.txt", "r")
out = open("output.txt", "w")

num_cases = int(inp.readline())
for case in xrange(num_cases):
    n, m = [int(a)*2 for a in inp.readline().split()]
    toys = [int(a) for a in inp.readline().split()]
    boxes = [int(a) for a in inp.readline().split()]
    main = toys
    other = boxes
    if n < m:
        other = toys
        main = boxes
    i = 0
    j = 0
    shipped = choose(boxes, toys, i, j, 0)
    out.write("Case #{0}: {1}\n".format(case+1, shipped))
