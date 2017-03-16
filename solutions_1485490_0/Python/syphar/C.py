#!/usr/bin/env python

import sys

def doit(boxes, toys):
    boxes = zip(
        [boxes[i] for i in range(len(boxes)) if i % 2 == 0],
        [boxes[i] for i in range(len(boxes)) if i % 2 == 1]
    )
    toys = zip(
        [toys[i] for i in range(len(toys)) if i % 2 == 0],
        [toys[i] for i in range(len(toys)) if i % 2 == 1]
    )

    #print boxes
    #print toys

    #strategie 1
    type_sums = [0]
    for t in set([x[1] for x in boxes]).intersection(set([x[1] for x in toys])):
        bc = sum([x[0] for x in boxes if x[1] == t])
        tc = sum([x[0] for x in toys if x[1] == t])

        type_sums.append(min(bc,tc))

    #strategie 2
    i_b = 0
    i_t = 0
    new_result = 0
    for inc in range(1, max(len(boxes),len(toys))):
        result = 0
        while i_b < len(boxes) and i_t < len(toys):
            box_count = boxes[i_b][0]
            box_type = boxes[i_b][1]

            toy_count = toys[i_t][0]
            toy_type = toys[i_t][1]

            if box_type == toy_type:
                if box_count == toy_count:
                    result = result + box_count
                    i_b = i_b + inc
                    i_t = i_t + inc
                elif box_count < toy_count:
                    result = result + box_count
                    i_b = i_b + inc
                    toys[i_t] = (toys[i_t][0] - box_count, toys[i_t][1])
                elif box_count > toy_count:
                    result = result + toy_count
                    boxes[i_b] = (boxes[i_b][0] - toy_count, boxes[i_b][1])
                    i_t = i_t + inc
            else:
                if box_count < toy_count:
                    i_b = i_b + inc
                elif box_count > toy_count:
                    i_t = i_t + inc
                else:
                    if i_t + inc < len(toys)-1 and toys[i_t + inc][1] == box_type:
                        i_t = i_t + inc
                    elif i_b + inc < len(boxes)-1 and boxes[i_b + inc][1] == toy_type:
                        i_b = i_b + inc
                    else:
                        i_t = i_t + inc
                        i_b = i_b + inc

        new_result = max(new_result, result)

    #strategie 3
    i_b = 0
    i_t = 0
    for inc in range(1, max(len(boxes),len(toys))):
        result = 0
        while i_b < len(boxes) and i_t < len(toys):
            box_count = boxes[i_b][0]
            box_type = boxes[i_b][1]

            toy_count = toys[i_t][0]
            toy_type = toys[i_t][1]

            if box_type == toy_type:
                if box_count == toy_count:
                    result = result + box_count
                    i_b = i_b + inc
                    i_t = i_t + inc
                elif box_count < toy_count:
                    result = result + box_count
                    boxes[i_b] = (boxes[i_b][0] - toy_count, boxes[i_b][1])
                    i_t = i_t + inc

                elif box_count > toy_count:
                    result = result + toy_count
                    i_b = i_b + inc
                    toys[i_t] = (toys[i_t][0] - box_count, toys[i_t][1])
            else:
                if box_count < toy_count:
                    i_b = i_b + inc
                elif box_count > toy_count:
                    i_t = i_t + inc
                else:
                    if i_t + inc < len(toys)-1 and toys[i_t + inc][1] == box_type:
                        i_t = i_t + inc
                    elif i_b + inc < len(boxes)-1 and boxes[i_b + inc][1] == toy_type:
                        i_b = i_b + inc
                    else:
                        i_t = i_t + inc
                        i_b = i_b + inc

        new_result = max(new_result, result)


    return max(new_result, max(type_sums))

def run():
    input = sys.stdin
    output = sys.stdout

    case_count = int(input.readline().strip())

    for caseno in range(case_count):
        item_counts = [int(x) for x in input.readline().strip().split()]
        boxes = [int(x) for x in input.readline().strip().split()][:item_counts[0]*2]
        toys = [int(x) for x in input.readline().strip().split()][:item_counts[1]*2]

        result = doit(boxes, toys)
        output.write("Case #{0}: {1}\n".format(caseno + 1, result))

if __name__ == '__main__':
    run()
