#!/usr/bin/python

N = int(raw_input())

def produce(toys, boxes, products):
    if len(toys) == 0 or len(boxes) == 0:
        return products

    toy_num, toy_type = toys[0]
    box_num, box_type = boxes[0]

    if toy_type == box_type:
        num = min(toy_num, box_num)
        box_num = box_num - num
        toy_num = toy_num - num
        products = products + num

        cboxes = boxes[:]
        ctoys  = toys[:]

        if box_num == 0:
            del cboxes[0]
        else:
            cboxes[0] = (box_num, box_type)

        if toy_num == 0:
            del ctoys[0]
        else:
            ctoys[0] = (toy_num, toy_type)

        return produce(ctoys, cboxes, products)

    left = produce(toys[1:], boxes, products)
    right = produce(toys, boxes[1:], products)
    
    return max(left, right)


for case in xrange(0, N):
    print "Case #" + str(case + 1) + ":",

    toys, boxes = map(int, raw_input().split(" "))
    toy_input = map(int, raw_input().split(" "))
    box_input = map(int, raw_input().split(" "))

    box_config = []
    toy_config = []

    for i in xrange(0, len(toy_input), 2):
        toy_config.append( (toy_input[i], toy_input[i+1]) )

    for i in xrange(0, len(box_input), 2):
        box_config.append( (box_input[i], box_input[i+1]) )

    products = produce(toy_config, box_config, 0)

    print products

