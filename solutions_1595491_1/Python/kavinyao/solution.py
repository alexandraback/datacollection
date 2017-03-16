from mapping import mapping

def apart_2(triplet):
    return (triplet[0] - triplet[2]) == 2

def optimal_max(threshold, surprising_num, totals):
    """
    calculate the maximal number of tripelts with best result > threshold
    """
    ascending_totals = sorted(totals)

    # round 1: see if enough triplets both surprising and qualified
    both_satisfied = 0
    for total in ascending_totals:
        triplet = mapping[total][0] # only use the larger one
        if apart_2(triplet) and triplet[0] >= threshold:
            both_satisfied += 1

    surprising_remaining = surprising_num
    hit_count = 0
    if both_satisfied > surprising_number:
        # in this case, smaller total first
        for total in ascending_totals:
            for triplet in mapping[total]:
                # surprising one first, non-surprising one second
                if surprising_remaining > 0:
                    if apart_2(triplet):
                        if triplet[0] >= threshold:
                            hit_count += 1
                            surprising_remaining -= 1
                        break
                    else:
                        if triplet[0] >= threshold:
                            hit_count += 1
                else:
                    if not apart_2(triplet) and triplet[0] >= threshold:
                        hit_count += 1
                        break
    else:
        # in this case, larget total first
        for total in reversed(ascending_totals):
            for triplet in mapping[total]:
                # surprising one first, non-surprising one second
                if surprising_remaining > 0:
                    if apart_2(triplet):
                        if triplet[0] >= threshold:
                            hit_count += 1
                        # we use it anyway
                        surprising_remaining -= 1
                        break
                    else:
                        if triplet[0] >= threshold:
                            hit_count += 1
                else:
                    if not apart_2(triplet) and triplet[0] >= threshold:
                        hit_count += 1
                        break

    return hit_count

if __name__ == '__main__':
    import sys
    with open(sys.argv[1]) as input_file:
        cases_num = int(input_file.next())
        with open('result', 'wb') as output_file:
            for i in range(cases_num):
                numbers = [int(s) for s in input_file.next().split(' ')]
                surprising_number = numbers[1]
                threshold = numbers[2]
                totals = numbers[3:]
                output_file.write('Case #%s: %s\n' % (i+1, optimal_max(threshold, surprising_number, totals)))
