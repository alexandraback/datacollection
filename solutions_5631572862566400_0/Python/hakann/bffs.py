def enlarge(list_of_circles):
    if len(list_of_circles) == 0:
        return 0
    maxx = len(list_of_circles[0])
    for circle in list_of_circles:
        for other_circle in list_of_circles:
            if circle[-1] == other_circle[-2] and circle[-2] == other_circle[-1]:
                new_l = len(set(circle+other_circle))
                if len(set(circle+other_circle)) > maxx:
                    maxx = new_l
    return maxx

def bffs(bff_pattern):
    bff_list = map(int, bff_pattern.split(' '))
    bff_dict = {}
    for i in range(len(bff_list)):
        bff_dict[i+1] = bff_list[i]
    complete_circles = []
    extendable_circles = []
    circle = []
    for i in bff_dict.keys():
        temp_bff = bff_dict[i]
        circle = [i, temp_bff]
        while bff_dict[temp_bff] not in circle:
            temp_bff = bff_dict[temp_bff]
            circle.append(temp_bff)
        if bff_dict[temp_bff] == circle[0]:
            complete_circles.append(circle)
        elif bff_dict[temp_bff] == circle[-2]:
            extendable_circles.append(circle)
    max_complete = max(map(len, complete_circles))
    biggest_ex = enlarge(extendable_circles)
    return max([max_complete, biggest_ex])

def formatted_output(index, final_count):
    return 'Case #' + str(index) + ': ' + str(final_count)

t = int(raw_input())  
for i in range(1, t + 1):
    n = raw_input()
    m = raw_input()
    print formatted_output(i, bffs(m))