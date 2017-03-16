def main_code(x):
    N = int(input())
    bffs = list(map(int, input().split()))
    for i in range(N):
        bffs[i] -= 1
        
    pairs = dict()
    for i, next in enumerate(bffs):
        if bffs[next] == i:
            pairs[i] = (i, next)
            pairs[next] = (next,i)
    
    
    bffs_best = dict()
    bests = set()

    for first in range(N):
        if first in bffs_best or first in pairs:
            continue
        row = [first]
        row_set = {first}
        current = first
        previous = None
        while True:
            next = bffs[current]
            if next in bffs_best:
                best = bffs_best[next]
                if best == None:
                    for i in row:
                        bffs_best[i] = None
                    break
                elif best[0][1]:
                    for i in row:
                        bffs_best[i] = None
                    break  
                elif best[1] >= len(row):
                    break
                else:
                    old_tup = best[0]
                    bests.remove(old_tup)
                    old_row, _, _ = old_tup
                    for i in old_row[:best[1]]:
                        del bffs_best[i]
                    row = row + list(old_row[best[1]:])
                    tup = (tuple(row), False, len(row))
                    bests.add(tup)
                    for n, i in enumerate(row):
                        bffs_best[i] = (tup, n)
                    break
            elif next in pairs:
                row += [next]
                tup = (tuple(row), False, len(row))
                bests.add(tup)
                for n, i in enumerate(row):
                    bffs_best[i] = (tup, n)
                break
            elif next == first:
                tup = (tuple(row), True, len(row))
                bests.add(tup)
                for i in row:
                    bffs_best[i] = (tup,)
                break
            elif next in row_set:
                index = row.index(next)
                for i in row[:index]:
                    bffs_best[i] = None
                row = row[index:]
                tup = (tuple(row), True, len(row))
                bests.add(tup)
                for i in row:
                    bffs_best[i] = (tup,)
                break
            else:
                row.append(next)
                row_set.add(next)
                previous = current
                current = next
                continue

    checked = set()
    combined = 0
    for a in pairs:
        if a not in checked:
            b = pairs[a][1]
            checked.add(a)
            checked.add(b)
            if a in bffs_best and b in bffs_best:
                combined += bffs_best[a][0][2] + bffs_best[b][0][2]
            elif a not in bffs_best and b not in bffs_best:
                combined += 2
            else:
                if b in bffs_best:
                    combined += bffs_best[b][0][2] + 1
                else:
                    combined += bffs_best[a][0][2] + 1
    result = max([combined] + [length for tup, circ, length in bests if circ])
    print("Case #" + str(x + 1) + ":", result)


T = int(input())
for x in range(T):
    main_code(x)
