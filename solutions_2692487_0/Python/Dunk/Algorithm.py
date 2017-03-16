__author__ = 'pard'


def output(output_file, case_list):
    """

    @param output_file: The file to open for writing
    @param case_list: A list object where each item is a case. Each will be converted to a string for output
    """
    with open(output_file, 'w') as f:
        for i, line in enumerate(case_list):
            f.write("Case #"+str(i+1)+": "+str(line)+"\n")


def process_variable_tables(input_file, output_file, algorithm):
    """

    @param input_file: Input file to process
    @param output_file: File to output to
    @param algorithm: The algorithm to use on each line of the file
    """
    import numpy as np
    with open(input_file, 'r') as f:
        input_lines = f.read().splitlines()

    num_cases = int(input_lines[0])
    out_strings = []

    line_counter = 1
    for table_number in range(num_cases):
        lines = []
        init_size = int(input_lines[line_counter].split()[0])
        num_motes = int(input_lines[line_counter].split()[1])
        motes = np.array([int(char) for char in input_lines[line_counter+1].split(' ') if char not in ['\n', '\r']])

        line_counter += 2
        #out_strings.append(algorithm(np.array(lines, dtype='a1')))
        out_strings.append(algorithm(init_size, motes))

    output(output_file, out_strings)



def algorithm(init_size, motes):
    operations = 0
    motes.sort()
    return recursive_operations(init_size, motes, 0)


def recursive_operations(init_size, sorted_motes, operations):
    import numpy as np
    mote_size = init_size
    # If mote size is one there'se notehing we can do so just remove all the other ones
    if mote_size == 1:
        return len(sorted_motes)

    for idx, mote in np.ndenumerate(sorted_motes):
        new_operations = 0
        # If we can't absorb this one then add the biggest new mote we can absorb and try and absorb it again
        while mote >= mote_size:
            mote_size += mote_size - 1
            new_operations += 1
        #  If it took more operations to do this than there are elements left we were better off just removing it and any subsequent ones
        if new_operations > len(sorted_motes) - idx[0]:
            new_operations = len(sorted_motes) - idx[0]
        #  tot up total current operations
        operations += new_operations
        #  if it's ever larger than the length of the list just remove them all instead
        if operations > len(sorted_motes):
            return len(sorted_motes)
        mote_size += mote

    return operations