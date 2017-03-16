'''
Created on Apr 12, 2014

@author: sergey

Problem D. Deceitful War
'''

import os


def get_data(fullpath):
    if(not os.path.exists(fullpath)):
        print 'file does not exist'
        return []

    result = []
    is_first_line = True
    number_of_test_cases = 0
    is_in_test_case = False
    line_in_test = 0
    with open(fullpath, 'r') as f:
        for line in f:

#             print '---', line_in_test, '---', line
            if(is_first_line):
                is_first_line = False
                t = int(line)
                if(t >= 1 and t <= 50):
                    print 'number of test cases', t
                    continue

                print 'invalid number of test cases', t
                return []

            if(is_in_test_case and line_in_test == 1):
                naomis_blocks = [float(i) for i in line.split(' ')]
                naomis_blocks.sort()
                if(result[-1]['n'] != len(naomis_blocks)):
                    print 'invalid number of naomis blocks, expected', result[-1]['n'], 'got', len(naomis_blocks)
                    return []
                result[-1]['naomis_blocks'] = naomis_blocks
                line_in_test += 1
            elif(is_in_test_case and line_in_test == 2):
                kens_blocks = [float(i) for i in line.split(' ')]
                kens_blocks.sort()
                if(result[-1]['n'] != len(kens_blocks)):
                    print 'invalid number of kens blocks, expected', result[-1]['n'], 'got', len(kens_blocks)
                    return []
                result[-1]['kens_blocks'] = kens_blocks
                line_in_test = 1
                is_in_test_case = False
            else:
                n = int(line)
                if(n < 1 or n > 1000):
                    print "invalid n", n
                    return []
                result += [{
                            'n': n,
                            'naomis_blocks': [],
                            'kens_blocks': []
                            }]

                is_in_test_case = True
                line_in_test = 1

                continue

    return result

def copy_item(item):
    return {
            'n': item['n'],
            'naomis_blocks': [i for i in item['naomis_blocks']],
            'kens_blocks': [i for i in item['kens_blocks']]
            }

def apply_ken_war_strategy(item, naomi_told):

    new_item = copy(item)

    larger_blocks = [i for i in new_item['kens_blocks'] if i > naomi_told]
    block_to_play = None
    ken_wins = None
    if(len(larger_blocks) > 0):
        block_to_play = min(larger_blocks)
        ken_wins = True
    else:
        block_to_play = min(new_item['kens_blocks'])
        ken_wins = False

    new_item['kens_blocks'] = new_item['kens_blocks'].remove(new_item['kens_blocks'].index(block_to_play))

    return ken_wins, new_item

# def apply_naomi_war_strategy(item):
#     new_item = copy_item(item)
#     block_to_play = max(new_item['naomis_blocks'])
#     new_item['naomis_blocks'] = new_item['naomis_blocks'].remove(new_item['naomis_blocks'].index(block_to_play))
#     return block_to_play, new_item

def apply_naomi_war_strategy(item):
    new_item = copy_item(item)



    number_of_times_naomi_wins = 0

#     print '-' * 75
#     print new_item['naomis_blocks']
#     print new_item['kens_blocks']

    for i in xrange(item['n']):


        if(new_item['naomis_blocks'][-1] > new_item['kens_blocks'][-1]):
            number_of_times_naomi_wins += 1

            new_item['naomis_blocks'] = new_item['naomis_blocks'][:-1]
            new_item['kens_blocks'] = new_item['kens_blocks'][1:]
        else:
            new_item['naomis_blocks'] = new_item['naomis_blocks'][:-1]
            new_item['kens_blocks'] = new_item['kens_blocks'][:-1]

#         print 'number_of_times_naomi_wins', number_of_times_naomi_wins
#         print new_item['naomis_blocks']
#         print new_item['kens_blocks']
#     print '-' * 75
    return number_of_times_naomi_wins


def apply_naomi_deceitful_war_strategy(item):
    new_item = copy_item(item)

    loosing_blocks = [new_item['naomis_blocks'][i] for i in xrange(len(new_item['naomis_blocks'])) if new_item['naomis_blocks'][i] < new_item['kens_blocks'][i]]
    while(len(loosing_blocks) > 0):
        new_item['naomis_blocks'] = new_item['naomis_blocks'][1:]
        new_item['kens_blocks'] = new_item['kens_blocks'][:-1]
        loosing_blocks = [new_item['naomis_blocks'][i] for i in xrange(len(new_item['naomis_blocks'])) if new_item['naomis_blocks'][i] < new_item['kens_blocks'][i]]

    return len(new_item['naomis_blocks'])


def main():

    input_filename = 'D-small-attempt0.in'
    output_filename = 'D-small-attempt0.out'

    data = get_data(input_filename)
    for item in data:
        print item

    print '-' * 75

    with open(output_filename, 'wb') as f:

        case_number = 0
        for item in data:
            case_number += 1

            print 'Case #%d: %d %d' % (case_number, apply_naomi_deceitful_war_strategy(item), apply_naomi_war_strategy(item))
            f.write('Case #%d: %d %d\n' % (case_number, apply_naomi_deceitful_war_strategy(item), apply_naomi_war_strategy(item)))

if __name__ == "__main__":
    main()
