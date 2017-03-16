__author__ = 'Reuben'



def solution(dom_size, width, height):
    if dom_size >= 7 or width*height % dom_size != 0 or dom_size > max(width,height):
        return "RICHARD"

    if dom_size == 1 or dom_size == 2:
        return "GABRIEL"

    if dom_size == 3:
        if height == 1 or width == 1:
            return "RICHARD"
        else:
            return "GABRIEL"

    if dom_size == 4:
        if (height <= 2 or width <= 2):
            return "RICHARD"
        else:
            return "GABRIEL"

    # if dom_size == 5:
    #     if (height <= 2 or width <= 2) or (height == 2 and width == 4) or (height == 4 and width == 2):
    #         return "RICHARD"
    #     else:
    #         return "GABRIEL"

f_in = open('file.in')
f_out = open('file.out','w')

cases = int(f_in.readline())
for i in range(1,cases+1):
    line = f_in.readline().split()
    dom_size = int(line[0])
    width = int(line[1])
    height = int(line[2])
    s = solution(dom_size, width, height)
    f_out.write("Case #"+str(i)+": "+s+"\n")