def calc_products(x, y, z):
    nums = [1]
    nums += [x]
    nums += [y]
    nums += [z]
    nums += [x * y]
    nums += [x * z]
    nums += [y * z]
    nums += [x * y * z]
    return nums


def prepare_array_dictionary():
    array_dictionary = []
    for x in xrange(126):
        array_dictionary += [{}]

    for x in xrange(2, 6):
        for y in xrange(2, 6):
            for z in xrange(2, 6):
                nums = [x, y, z]
                nums.sort()
                key = '%d%d%d' % (nums[0], nums[1], nums[2])
                products = calc_products(x, y, z)
                for product in products:
                    cur_dict = array_dictionary[product]
                    if key not in cur_dict:
                        cur_dict[key] = 1
                    else:
                        cur_dict[key] += 1
    return array_dictionary


def calc_ans(product_array_dictionary, nums):
    dicts = []
    for x in nums:
        dicts += [product_array_dictionary[x]]
    # check for 1-element dict
    for x in dicts:
        x = dict(x)
        if len(x) == 1:
            return x.keys()[0]  # TODO: check it
    # merge dicts
    points = {}
    for x in dicts:
        x = dict(x)
        length = len(x)
        for key in x.keys():
            if key not in points:
                points[key] = float(x[key]) / length
            else:
                points[key] += float(x[key]) / length
    # get max value
    max_point = max(points.values())
    for key in points.keys():
        if points[key] == max_point:
            return key


def main():
    filename = 'input_c.in'
    filename_out = 'output_c.txt'
    result_lines = []

    product_array_dictionary = prepare_array_dictionary()
    with open(filename, 'r') as input_file:
        input_file.readline()
        input_file.readline()
        result_lines += ['Case #1:\n']
        for test in xrange(100):
            nums = [int(x) for x in input_file.readline().split()]
            ans = calc_ans(product_array_dictionary, nums)
            result_lines += [ans + '\n']
    with open(filename_out, 'w') as output_file:
        output_file.writelines(result_lines)


main()
