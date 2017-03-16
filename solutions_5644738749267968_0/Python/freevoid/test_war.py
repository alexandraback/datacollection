import random

import war


def generate_random_inputs(maxn=1000, iterations=100):
    for i in range(iterations):
        n = random.randrange(1, maxn + 1)
        naomis = [random.random() for i in range(n)]
        kens = [random.random() for i in range(n)]
        yield n, naomis, kens


def test_random_inputs():
    for n, naomis, kens in generate_random_inputs(iterations=100):
        score_deceitful, score_honest = war.get_scores(n, naomis, kens)
        assert isinstance(score_deceitful, int)
        assert isinstance(score_honest, int)
        assert score_deceitful >= 0
        assert score_honest >= 0


def get_sample_cases():
    yield 1, [0.5], [0.6], (0, 0)
    yield 2, [0.7, 0.2], [0.8, 0.3], (1, 0)
    yield 3, [0.5, 0.1, 0.9], [0.6, 0.4, 0.3], (2, 1)
    yield 9, [0.186, 0.389, 0.907, 0.832, 0.959, 0.557, 0.300, 0.992, 0.899], [0.916, 0.728, 0.271, 0.520, 0.700, 0.521, 0.215, 0.341, 0.458], (8, 4)


def test_sample_cases():
    for n, naomis, kens, expected in get_sample_cases():
        actual = war.get_scores(n, naomis, kens)
        assert actual == expected, 'Sample case produced incorrect result: %s != %s' % (actual, expected)
