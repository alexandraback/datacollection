import fileinput
import logging
import sys

logging.basicConfig(stream=sys.stderr,level=logging.DEBUG)

nTest = 0
line_no = 0
instances = []

first_instance_line = True

for line in fileinput.input():
    if line_no == 0:
        nTest = int(line)
        logging.debug("%d" % nTest)
    else:
        a = line.split()
        (R,C,W) = (int(a[0]),int(a[1]),int(a[2]))
        instances.append((R,C,W))
        logging.debug("%d %d %d" % (R,C,W))
    line_no+=1

memo = {}


array =[];

def instance(inst):
    (R,C,W) = inst
    logging.debug("R %d  C %d  W %d" % (R,C,W))
    val = 0
    if C%W != 0:
        val = 1
    return (C/W)*R + (W-1) +val

out_line_no = 1
for x in instances:
    solution = instance(x)
    print "Case #%d: %d" % (out_line_no, instance(x))
    out_line_no+=1


