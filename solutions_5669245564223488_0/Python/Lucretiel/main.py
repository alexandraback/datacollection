from code_jam import autosolve
from functools import lru_cache

@lru_cache(maxsize=None)
def can_add_train(current_back, letters, train):
    train = train.lstrip(current_back)
    while train:
        if letters.intersection(train):
            return False
        letters = letters | {train[0]}
        train = train.lstrip(train[0])
    return True

@lru_cache(maxsize=None)
def removed(container, index):
    return container[:index] + container[index+1:]

@lru_cache(maxsize=None)
def count_orderings(current_back, letters, trains):
    if trains:
        return sum(count_orderings(
                train[-1],
                letters | set(train),
                removed(trains, i))

            for i, train in enumerate(trains)

            if can_add_train(current_back, letters, train))
    else:
        return 1

@autosolve
def trains(tokens):
    return count_orderings('', frozenset(),
        tuple(tokens.next_counted_tokens(str)))
