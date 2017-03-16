"""
A collection of small, helpful functions I'll be using a lot.

Author: 
  Chris Nitsas
  (nitsas)

Language:
  Python 3(.4)

Date:
  April, 2012
"""


__name__ = 'helpful'
__all__  = ['read_int', 'read_float', 'read_list_of_str', 
            'read_list_of_int', 'read_list_of_float', 'read_list_of_types']


# In every function below, 'file' is an open file object.


def read_int(file):
    return int(file.readline())


def read_float(file):
    return float(file.readline())


def read_str(file):
    return file.readline().rstrip('\n')


def read_list_of_str(file):
    return file.readline().split()


def read_list_of_int(file):
    return list(map(int, read_list_of_str(file)))


def read_list_of_float(file):
    return list(map(float, read_list_of_str(file)))


def read_list_of_types(file, target_types):
    """
    Read a line of parts separated by whitespace and convert each part to the
    corresponding type in target_types. Return a list.
    
    target_types -- a list of callables representing types; 
                    so, e.g. target_types[0](part) should be able to convert
                    the string in 'part' to the desired type
    
    Example:
    If we want to read a line containing an int, a strint, and a float we can
    call read_list_of_types(file, [int, str, float]), and (if all goes well) 
    we will get a list with an int, a string, and a float
    """
    line_parts = read_list_of_str(file)
    assert(len(line_parts) == len(target_types))
    return list(type_(part) for type_, part in zip(target_types, line_parts))


def is_odd(num):
    return num & 1 == 1


def is_even(num):
    return not (num & 1 == 1)
